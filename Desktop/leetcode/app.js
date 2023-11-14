// Create a new Map to store balances
let transactions = new Map();

// Function to add a bill to the map
function addBill(user1, user2, amount) {
  // Subtract the amount from user1's balance
  transactions.set(user1, (transactions.get(user1) || 0) - amount);
  // Add the amount to user2's balance
  transactions.set(user2, (transactions.get(user2) || 0) + amount);
}

// Function to settle transactions between users
function settleTransactions(balanceMap) {
  // Convert the balanceMap to an array of entries and sort it by balance in descending order
  const sortedBalances = Object.entries(balanceMap).sort((a, b) => b[1] - a[1]);
  const transactions = [];

  // Iterate through the sorted balances
  for (let i = 0; i < sortedBalances.length; i++) {
    const [payer, positiveBalance] = sortedBalances[i];

    // Skip individuals with non-positive balances
    if (positiveBalance <= 0) {
      continue;
    }

    // Iterate through the sorted balances in reverse order
    for (let j = sortedBalances.length - 1; j > i; j--) {
      const [payee, negativeBalance] = sortedBalances[j];

      // Skip individuals with non-negative balances
      if (negativeBalance >= 0) {
        continue;
      }

      // Calculate the transaction amount as the minimum of positive and absolute negative balances
      const transactionAmount = Math.min(positiveBalance, Math.abs(negativeBalance));

      // Update balances for payer and payee
      sortedBalances[i][1] -= transactionAmount;
      sortedBalances[j][1] += transactionAmount;

      // Record the transaction details
      transactions.push({ from: payer, to: payee, amount: transactionAmount });

      // Break if the positive balance is fully utilized
      if (sortedBalances[i][1] === 0) {
        break;
      }
    }
  }

  return transactions;
}

// Sample input data
let jsonResponce = [
  { payer: "Jan", payee: "Piet", amount: 50 },
  { payer: "Piet", payee: "Henk", amount: 30 },
  { payer: "Henk", payee: "Ingrid", amount: 40 },
  { payer: "Ingrid", payee: "Klaas", amount: 80 },
  { payer: "Piet", payee: "Ingrid", amount: 20 }
];

// Process bills and create a Map of transactions
for (let i = 0; i < jsonResponce.length; i++) {
  addBill(jsonResponce[i].payer, jsonResponce[i].payee, jsonResponce[i].amount);
}

// Convert the Map of transactions to an object
const transactionObj = Object.fromEntries(transactions);

// Settle the transactions and log the result
const result = settleTransactions(transactionObj);
console.log(result);
