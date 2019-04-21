using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RangedWeapons : MonoBehaviour {


    Ray shootRay;
    RaycastHit shootHit;
    float range = 50f;
    int shootableMask;
    Vector3 shootBlast;

	// Use this for initialization
	void Start () {
        shootRay.origin = transform.position;
        shootRay.direction = transform.forward;
        //shootRay.direction = Input.mousePosition;
        //shootBlast = new Vector3(Input.mousePosition.x, Input.mousePosition.y, 0f);
    }
	
	// Update is called once per frame
	void Update () {
        shootableMask = 8;
        shootableMask = ~shootableMask;
        // everything but 8 can be shootable
        Fire();
	}

    public void Fire()
    {
        if(Input.GetMouseButton(0))
        {
            Hitscan();
        }
    }

    private void Hitscan()
    {
        Debug.Log(transform.TransformDirection(Vector3.forward));
        Debug.Log(shootHit);
        //Physics2D.Raycast(transform.position,)
        
        if (Physics.Raycast(transform.position,
            transform.TransformDirection(Vector3.forward),
            out shootHit,
            range,
            shootableMask
            ))
        {
            Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.forward) * shootHit.distance, Color.white);
            Debug.Log("did hit");
        }
        else
        {
            Debug.DrawRay(transform.position, transform.TransformDirection(Vector3.forward) * 500, Color.yellow);
            Debug.Log("did not hit");
        }
        
        /*
        if (Physics.Raycast(shootRay,
            out shootHit,
            range,
            shootableMask
            ))
        {
            Debug.DrawRay(transform.position, shootBlast * shootHit.distance, Color.white,15f);
            Debug.Log("did hit");
        }
        else
        {
            Debug.DrawRay(transform.position, shootBlast * 500, Color.yellow,15f);
            Debug.Log("did not hit");
        }
        */

    }
}
