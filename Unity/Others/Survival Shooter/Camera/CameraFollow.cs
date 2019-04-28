using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour {

	public Transform target;
	public float smoothing = 5f;
	//how smooth it is

	Vector3 offset;

	void Start()
	{
		offset = transform.position - target.position;
		//vector from camera to the player
	}
	void FixedUpdate()
	{
		Vector3 targetCamPos = target.position + offset;
		//position of the target+offset
		transform.position = Vector3.Lerp (transform.position, targetCamPos, smoothing * Time.deltaTime);
	}

}
