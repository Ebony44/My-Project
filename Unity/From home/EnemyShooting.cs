using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyShooting : MonoBehaviour {

    public float timeBtwShots;
    public float startTimeBtwShots;

    [SerializeField] public GameObject projectile;

	// Use this for initialization
	void Start () {

        timeBtwShots = startTimeBtwShots;
	}
	
	// Update is called once per frame
	void Update () {
		
        if(timeBtwShots <= 0)
        {
            Instantiate(projectile, transform.position, Quaternion.identity);
            timeBtwShots = startTimeBtwShots;
        }
        else
        {
            timeBtwShots -= Time.deltaTime;
        }

	}
}
