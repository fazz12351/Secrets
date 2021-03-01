using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Player_Movement : MonoBehaviour
{
  
    public Text countText;
    private int count;

    // Start is called before the first frame update
    void Start()
    {
        count = 0;
        SetCountText();
    }
   
    void FixedUpdate()
    {
      
    }

    private void OnTriggerEnter(Collider other) //everything located in this void allows the score of each game object to be calculated
    {
        if (other.gameObject.CompareTag("Pick Up")) //the game object being refenced is called "Regular Pick Up"
        {
            other.gameObject.SetActive(false);
            count = count + 1; //when the player collides with the "Regular Pick Up" object 1 point will be added to the overall score
            SetCountText();
        }

        else if (other.gameObject.CompareTag("Bonus Pick Up"))
        {
            other.gameObject.SetActive(false);
            count = count + 2; //when the player collides with the "Bonus Pick Up" object 2 points will be added to the overall score
            SetCountText();
        }

        else if (other.gameObject.CompareTag("Special Pick Up"))
        {
            other.gameObject.SetActive(false);
            count = count + 10; //when the player collides with the "Special Pick Up" object 10 points will be added to the overall score
            SetCountText();
        }


        else if (other.gameObject.CompareTag("Sandbox_select"))
        {
            other.gameObject.SetActive(false);
            SceneManager.LoadScene(2);
        }

        else if (other.gameObject.CompareTag("Select_level1"))
        {
            other.gameObject.SetActive(false);
            SceneManager.LoadScene(1);

        }

    }
    void SetCountText()
    {
        countText.text = "Score: " + count.ToString();
        //this will conver the calaculations made from "SetCountText" into a string 
        //so the actual number can be displayed on screen
    }

}
