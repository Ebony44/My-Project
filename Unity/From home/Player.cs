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
    float xMaxSpeed = 18;
    float yMaxSpeed = 16;

    //bool bIsleft = false;
    [SerializeField] bool bIsturned = true;
    
    
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
        float zAngle2 = 1 / Mathf.Atan2(pointDirection.y, pointDirection.x) * Mathf.Rad2Deg;
        float zAngle3 = Mathf.Atan(pointDirection.y / pointDirection.x) * Mathf.Rad2Deg;
        //Debug.Log("zAngle is " + zAngle);
        //Debug.Log("zAngle2 is " + zAngle2);
        float yAngle;
        // rotation.y
        // rotation.z
        // ... etc

        
        Quaternion rotation = Quaternion.AngleAxis(zAngle, Vector3.forward);
        Quaternion rotation2 = Quaternion.AngleAxis(zAngle2, Vector3.forward);
        //Quaternion rotation3 = Quaternion.AngleAxis(zAngle3, Vector3.forward);


        // negatvie and equal to or larger than positive
        if (pointDirection.x < 0 && bIsturned)
        {
            yAngle = -180f;
            //transform.GetChild(1).GetChild(0).Rotate(Vector3.up, yAngle);
            //bIsturned = false;

            rotation2 = Quaternion.Euler(0f, 180f, zAngle2);
            transform.rotation = Quaternion.Slerp(transform.rotation, rotation2, rotationSpeed * Time.deltaTime);

        }
        else if(pointDirection.x >= 0 && bIsturned)
        {
            yAngle = 180f;
            //transform.GetChild(1).GetChild(0).Rotate(Vector3.up, yAngle);
            //bIsturned = false;

            transform.rotation = Quaternion.Slerp(transform.rotation, rotation, rotationSpeed * Time.deltaTime);

        }
        
        Vector2 mousePosV2 = new Vector2(Camera.main.ScreenToWorldPoint(Input.mousePosition).x, 
            Camera.main.ScreenToWorldPoint(Input.mousePosition).y);
        //transform.LookAt(mousePosV2);
        
        
        
        
        //transform.Rotate(0f, yAngle, zAngle);
        
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
    /*
    private IEnumerator DirectionStaring(bool bIsturned)
    {
        bool bLooping = false;
        do
        {
            yield return new WaitForSeconds(1f);
        } while (bLooping);
        
        //TODO get mousePosition and make the model stare that direction.
    }
    */
    
}
