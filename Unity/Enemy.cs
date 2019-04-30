using UnityEngine;

public class Enemy : MonoBehaviour {


    [Header("MovementAdjustValue")]
    [SerializeField] private float movementSpeed;
    public float MovementSpeed { get{ return movementSpeed;} set { movementSpeed = value;} }
    [SerializeField] float movementSpeedRate = 1f;


    Vector3 PlayerPosition;
    
    private void Start() 
    {
        PlayerPosition = FindObjectOfType<Player>();
    }

    private void Update() 
    {
        
    }

    void MeleeMove()
    {
        // TODO just move to Player's transform.position and act
        transform.Translate(Vector3.right * Time.deltaTime);
        void OnCollisionEnter(Collision collision)
        {
            
        }
    }

    void JumperMove()
    {
        // TODO move like with altered z axis or scale
    }
    
    void CaterpillarMove()
    {
        // TODO move with interval times
    }


    
}