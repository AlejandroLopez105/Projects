using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
public class Player : MonoBehaviour
{
    public SerialPort stream = new SerialPort("COM15", 9600);
    public float speed = 18;
    private Rigidbody rig;
    public GameObject right_index;
    public GameObject left_index;
    void OnEnable()
    {
        stream.Open();
    }
    void OnDisable()
    {
        stream.Close();
    }
    void Start()
    {
        rig = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        string raw = stream.ReadLine();
        if (raw != null)
        {
            float value;
            if(float.TryParse(raw, out value))
            {
                //float value = float.Parse(raw);
                if (value == 2.0)
                {
                    Vector3 movement = new Vector3(3, 0, 0) * speed * Time.deltaTime;
                    rig.MovePosition(transform.position + movement);
                    Vector3 rhidx = new Vector3(0, 45, 0) * Time.deltaTime;
                    right_index.transform.Rotate(rhidx);
                }
                if (value == 4.0)
                {
                    Vector3 movement = new Vector3(-3, 0, 0) * speed * Time.deltaTime;
                    rig.MovePosition(transform.position + movement);
                    Vector3 rhidx = new Vector3(0, -45, 0) * Time.deltaTime;
                    right_index.transform.Rotate(rhidx);
                }
                if (value == 7.0)
                {
                    Vector3 movement = new Vector3(0, 0, 3) * speed * Time.deltaTime;
                    rig.MovePosition(transform.position + movement);
                    Vector3 lhidx = new Vector3(0, 45, 0) * Time.deltaTime;
                    left_index.transform.Rotate(lhidx);
                }
                if (value == 8.0)
                {
                    Vector3 movement = new Vector3(0, 0, -3) * speed * Time.deltaTime;
                    rig.MovePosition(transform.position + movement);
                    Vector3 lhidx = new Vector3(0, -45, 0) * Time.deltaTime;
                    left_index.transform.Rotate(lhidx);
                }

            }
        }
    }
}
/*using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//using System.IO.Ports;
public class Player : MonoBehaviour
{
    //public SerialPort stream = new SerialPort("COM15", 9600);
    public wrmhl device = new wrmhl();
    //public Transform a;
    //public Transform b;

    void OnEnable() {
        device.set("COM15", 9600);
        device.connect();
    }
    void OnDisable()
    {
        device.close();
    }

    // Update is called once per frame
    void Update()
    {
        string raw = device.readQueue();
        if (raw != null)
        {
            int value = int.Parse(raw);
            print(value);
        }
    }
}

if (Input.GetKeyDown(KeyCode.LeftArrow))
        {
            Vector3 position = this.transform.position;
            position.x--;
            this.transform.position = position;
        }*/