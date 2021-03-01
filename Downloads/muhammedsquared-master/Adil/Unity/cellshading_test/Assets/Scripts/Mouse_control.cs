using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mouse_control : MonoBehaviour
{
    

    public float speedH = 2.0f;
    public float speedV = 2.0f;

    private float x_axis = 0.0f;
    private float y_axis = 0.0f;



    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        x_axis += speedH * Input.GetAxis("Mouse X");
        y_axis -= speedV * Input.GetAxis("Mouse Y");

        transform.eulerAngles = new Vector3(y_axis, x_axis, 0.0f);

    }
}
