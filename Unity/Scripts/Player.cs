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
        // ArcTangent y/x * 180/PI
        // 1 Rad * 180/PI = Degrees
        // y = -1, x = -1
        // dir = atan(y/x);  % returns 0.78540 rad = 45 deg
        // dir2 = atan2(y, x); % returns -2.3562 rad = -135 deg.
        // tan A = y/x
        // tan 

        Vector2 pointDirection = Camera.main.ScreenToWorldPoint(Input.mousePosition) - transform.position;
        float zAngle = Mathf.Atan2(pointDirection.y, pointDirection.x) * Mathf.Rad2Deg;
        float yAngle;
        // rotation.y
        // rotation.z
        // ... etc

        // negatvie and equal to or larger than positive
        if(pointDirection.x < 0)
        {
            yAngle = 180f;
        }
        else
        {
            yAngle = 0f;
        }

        Quaternion rotation = Quaternion.AngleAxis(zAngle, Vector3.forward);
        //Vector3.forward will return (0,0,1) and angle will rotate around that axis.
        //which means z axis and z rotation.
        Quaternion childRotation = transform.GetChild(1).rotation;
        childRotation = Quaternion.AngleAxis(yAngle, Vector3.up);

        transform.GetChild(1).rotation = Quaternion.Slerp(transform.GetChild(1).rotation, childRotation, rotationSpeed * Time.deltaTime);
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
    
}
