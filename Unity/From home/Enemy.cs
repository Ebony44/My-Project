using UnityEngine;

public class Enemy : MonoBehaviour {


    [Header("MovementAdjustValue")]
    [SerializeField] private float movementSpeed;
    public float MovementSpeed { get{ return movementSpeed;} set { movementSpeed = value;} }
    [SerializeField] float movementSpeedRate = 0.2f;


    [Header("ShooterMovement")]
    [SerializeField] public float stoppingDistance;
    [SerializeField] public float retreatDistance;
    //public float stoppingDistance;

    public Transform player;
      



    Vector3 PlayerPosition;
    
    private void Start() 
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
    }

    private void Update() 
    {
        //MeleeMove();
        ShooterMove();
        

    }

    void MeleeMove()
    {
        // TODO just move to Player's transform.position and act
        //transform.Translate(Vector3.right * Time.deltaTime);
        PlayerPosition = FindObjectOfType<Player>().transform.position;
        transform.Translate((PlayerPosition - transform.position) * Time.deltaTime * movementSpeedRate);
        //Invoke("Debugiing", 1f);
        
    }
    void ShooterMove()
    {
        if (Vector2.Distance(transform.position, player.position) > stoppingDistance)
        {
            transform.position = Vector2.MoveTowards(transform.position, player.position, movementSpeed * Time.deltaTime);

        }
        else if (Vector2.Distance(transform.position, player.position) < stoppingDistance
            && Vector2.Distance(transform.position, player.position) > retreatDistance)
        {
            transform.position = this.transform.position;
        }
        else if (Vector2.Distance(transform.position, player.position) < retreatDistance)
        {
            transform.position = Vector2.MoveTowards(transform.position, player.position, -movementSpeed * Time.deltaTime);
        }
    }
    void Debugging()
    {
        Debug.Log(PlayerPosition - transform.position);
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