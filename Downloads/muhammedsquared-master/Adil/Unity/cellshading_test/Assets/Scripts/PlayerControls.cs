using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;


public class PlayerControls : MonoBehaviour
{

    public Rigidbody player;
    public float defaultSpeed = 10.0f;
    private AudioSource audioSource;

    public float jumpForce = 5.0f;
    //public float fallMultiplyer = 2.5f;
    //public float lowMultiplyer = 2f;
    public GameObject ground;
    public AudioClip bounce;
    public bool isGrounded;


    public float sprintSpeed = 5.0f;

    private bool isSprinting;

    // Update is called once per frame
    void FixedUpdate()
    {
        MoveFowards();

        MoveBackwards();

        MoveLeft();

        MoveRight();

        Jump();

        Sprint();

        Restart();
    }


    void Start()
    {
        audioSource = GetComponent<AudioSource>();

        player = this.GetComponent<Rigidbody>();
    }

    void OnCollisionEnter(Collision obj)
    //if a game obect is tagged with "Ground" the player is able to jump on that object
    {
        if (obj.gameObject.tag == "Ground")
        {
            isGrounded = true;

            audioSource.PlayOneShot(bounce);
        }
    }

    public void MoveFowards() //when the player presses the "W" or "UpArrow" keys the player will move forward
    {
        if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.UpArrow))
        {
            player.AddForce(0, 0, defaultSpeed * Time.deltaTime, ForceMode.VelocityChange);
        }
    }

    public void MoveBackwards() //when the player presses the "S" or "DownArrow" keys they player will move backwards
    {

        if (Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
        {
            player.AddForce(0, 0, -defaultSpeed * Time.deltaTime, ForceMode.VelocityChange);
        }
    }

    public void MoveLeft() //when the player presses the "A" or "LeftArrow" keys they player will move left
    {

        if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
        {
            player.AddForce(-defaultSpeed * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
        }
    }

    public void MoveRight() //when the player presses the "" or "RightArrow" keys they player will move to the right
    {
        if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
        {
            player.AddForce(defaultSpeed * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
        }
    }

    public void Sprint() //when the user presses the left shift key the player will accelerate
    {
        if (Input.GetKeyDown(KeyCode.LeftShift))
        {
            if (!isSprinting)
            {
                defaultSpeed += sprintSpeed;
                isSprinting = true;
            }
        }

        if (Input.GetKeyUp(KeyCode.LeftShift))
        {
            if (isSprinting)
            {
                defaultSpeed -= sprintSpeed;
                isSprinting = false;
            }
        }
    }

    public void Jump() //when the user presses the space bar they ball will jump on objects tagged with "ground"
    {
        if (Input.GetKey(KeyCode.Space) && isGrounded)
        {
            player.AddForce(0, jumpForce, 0, ForceMode.Impulse);

            isGrounded = false;
        }
    }


    public void Restart() //when the player presses the "R" key the game will restart
    {
        if (Input.GetKey(KeyCode.R))
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
        }
    }
}