let map = new Map();

function addBill(user1, user2, amount) {
  if (map.has(user1)) {
    map.set(user1, map.get(user1) - amount);
    if (map.has(user2)) {
      map.set(user2, map.get(user2) + amount);
    } else {
      map.set(user2, amount);
    }
  } else {
    map.set(user1, 0);
    addBill(user1, user2, amount);
  }
}

addBill("Jan", "Piet", 50);
addBill("Piet","Henk",30)
addBill("Henk","Ingrid",40)
addBill("Ingrid","Klaas",80)
addBill("Piet","Ingrid",20)

console.log(map);
