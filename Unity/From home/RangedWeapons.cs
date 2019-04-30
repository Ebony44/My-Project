//using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RangedWeapons : MonoBehaviour {

    float timer;

    [Header("Hitscan Weapon")]
    [SerializeField] float firstFireRate=2f;
    [SerializeField] float afterFireRate=1f;
    [SerializeField] float effectDisplayTime = 0.2f;


    Ray shootRay = new Ray();
    RaycastHit shootHit;
    
    int shootableMask;
    LineRenderer laserline;

    float range = 50f;
    [SerializeField] private float accuracy;
    public float Accuracy { get {return accuracy;} set { accuracy = value;} }
    
    Vector2 mousePosV2;
    Vector3 shootBlast;
    Vector3 shootDirection;

    Coroutine firingCoroutine;

    void Start () {
        shootRay.origin = transform.position;
        shootRay.direction = transform.forward;
        Accuracy = 1.5f;

        shootableMask = LayerMask.GetMask("Player");
        shootableMask = ~shootableMask;
        //shootableMask = 8;
        //shootableMask = ~shootableMask;

        // Vector3.
        //shootRay.direction = Input.mousePosition;
        //shootBlast = new Vector3(Input.mousePosition.x, Input.mousePosition.y, 0f);
        laserline = GetComponent<LineRenderer>();
    }
    
	
	// Update is called once per frame
	void Update () 
    {
        timer += Time.deltaTime;
        Fire();
	}

    public void Fire(float afterFireRate)
    {
        /*
        if(Input.GetMouseButton(0))
        {
            //Hitscan(Accuracy);
        }
        */
        if(Input.GetButtonDown("Fire1") && afterFireRate >= timer)
        {
            //firingCoroutine = StartCoroutine(Hitscan(Accuracy, afterFireRate));
            Hitscan(Accuracy);
        }
        else if(Input.GetButtonUp("Fire1"))
        {
            //StopCoroutine(firingCoroutine);
        }
    }

    //TODO bring Parameter "DamageDealer damage"
    private void Hitscan(float accuracy)//, float afterFireRate)
    {
        while(true)
        {
            laserline.SetPosition(0, transform.position);
            laserline.enabled = true;


            mousePosV2 = Camera.main.ScreenToWorldPoint(Input.mousePosition) - transform.position;
            accuracy = Random.Range(0, mousePosV2.y + accuracy);
            shootDirection = new Vector3(mousePosV2.x, accuracy, 0f);
            Debug.Log("transform.position is " + transform.position + "mouse is " + mousePosV2);

            if (Physics.Raycast(transform.position,
                shootDirection,
                //transform.TransformDirection(Vector3.right),
                out shootHit,
                range,
                shootableMask
                ))
            {
                laserline.SetPosition(1, shootHit.point);

                Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.right) * shootHit.distance, Color.white);
                Debug.Log("did hit");
            }
            else
            {
                //laserline.SetPosition(1, shootRay.origin + shootRay.direction * range);
                laserline.SetPosition(1, shootDirection * range / 10f);
                Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.right) * 500, Color.yellow);
                Debug.Log("did not hit");

            }
            
            //yield return new WaitForSeconds(afterFireRate);

            
            
        }
        
        
    }
    private void Projectile()
    {
        // TODO Instatiate() -> sprite and it's Vector3 someVector.Velocity()
        // after if it works well after debugging -> separate this method to class
        // same goes to Hitscan()
    }
}
