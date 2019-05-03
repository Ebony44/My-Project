using UnityEngine;

public class ScreenManager : MonoBehaviour {
    
    public float maxThrust;
    public float maxTorque;
    public Rigidbody2D rb;

    public float screenTop;
    public float screenBottom;
    public float screenLeft;
    public float screenRight;

    private void Start() {
        Vector2 thrust = new Vector2(Random.Range(-maxThrust,maxThrust),Random.Range(-maxThrust,maxThrust));
        float torque = Random.Range(-maxTorque,maxTorque);

        rb.AddForce(thrust);
        rb.AddTorque(torque);
    }

    private void Update() {
        
    }
    // measure the screen's out of edge and take down the values ->
    // now modify the modeling's movement with boundary functions
    // 
    private void ScreenWrapping()
    {
        Vector2 newPos = transform.position;
        if(transform.position.y > screenTop)
        {
            newPos.y = screenBottom;
        }
        if(transform.position.y < screenBottom)
        {
            newPos.y = screenTop;
        }
        if(transform.position.x > screenRight)
        {
            newPos.x = screenLeft;
        }
        if(transform.position.x < left)
        {
            newPos.x = screenRight;
        }
        transform.position = newPos;

    }

}