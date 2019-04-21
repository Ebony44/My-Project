using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Player : MonoBehaviour {

    [SerializeField] float padding = 0.6f;
    [SerializeField] float moveSpeedRate = 12f;
    [SerializeField] float rotationSpeed = 4f;
    Camera cam;
    float camZPos;
    float xMinSpeed = 0;
    float yMinSpeed = 0;
    float xMaxSpeed = 16;
    float yMaxSpeed = 16;
    
    
    // Use this for initialization
    void Start ()
    {
        cam = FindObjectOfType<Camera>();
        camZPos = cam.transform.position.z + 10f;
    }
        

	
	// Update is called once per frame
	void Update ()
    {
        
        Vector2 pointDirection = Camera.main.ScreenToWorldPoint(Input.mousePosition) - transform.position;
        float angle = Mathf.Atan2(pointDirection.y, pointDirection.x) * Mathf.Rad2Deg;
        Quaternion rotation = Quaternion.AngleAxis(angle, Vector3.forward);
        transform.rotation = Quaternion.Slerp(transform.rotation, rotation, rotationSpeed * Time.deltaTime);
        


        Movement();
	}

    public void Movement()
    {
        
        //Vector3 mousePos = Input.mousePosition;
        //fixing instant move issue
        //Vector3 mousePos = Input.mousePosition.normalized;
        //Vector3 mousePosSpeed = new Vector3(1, 1, 0f)
        //Vector3 cursorPos = cam.ScreenToWorldPoint(new Vector3(mousePos.x, mousePos.y, 0f));
        float deltaX = Input.GetAxis("Horizontal") * Time.deltaTime * moveSpeedRate;
        float deltaY = Input.GetAxis("Vertical") * Time.deltaTime * moveSpeedRate;
        float paddlePosX = Mathf.Clamp(transform.position.x + deltaX, xMinSpeed, xMaxSpeed);
        float paddlePosY = Mathf.Clamp(transform.position.y + deltaY, yMinSpeed, yMaxSpeed);
        Vector3 paddlePos = new Vector3(paddlePosX, paddlePosY, camZPos);
        /*
         * 

        That is the current mouse position. 
        The issue is that 
        your objects are in world coordinates and 
        the mouse is using screen coordinates.

        You need to convert the mouse position using Camera.ScreenToWorldPoint().
        */
        transform.position = paddlePos;
    }
    private void SetupBoundaries()
    {
        xMinSpeed = cam.ViewportToWorldPoint(new Vector3(0, 0, 0)).x + padding;
        xMaxSpeed = cam.ViewportToWorldPoint(new Vector3(1, 0, 0)).x + padding;
        yMinSpeed= cam.ViewportToWorldPoint(new Vector3(0, 0, 0)).y + padding;
        yMaxSpeed = cam.ViewportToWorldPoint(new Vector3(0, 1, 0)).y + padding;
    }
    private void DirectionStaring()
    {
        //TODO get mousePosition and make the model stare that direction.
    }
    void Rotating()
    {

    }
}
