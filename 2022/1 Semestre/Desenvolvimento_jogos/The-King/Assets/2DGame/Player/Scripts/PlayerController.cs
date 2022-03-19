using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public Rigidbody2D rb; //variavel do corpo rigido
    public Vector2 vel;
    /*public float speed;
    public float jumpForce;
    private float direction;

    private Vector3 facingRight;
    private Vector3 facingLeft;
    */

    // Start is called before the first frame update
    void Start()
    {
        /*facingRight = transform.localScale;
        facingLeft = transform.localScale;
        facingLeft.x = facingLeft.x * -1;
        */
        rb = GetComponent<Rigidbody2D>();
        vel = new Vector2(5 ,0);
    }

    // Update is called once per frame
    void Update()
    {
        //captando comando para andar horizontalmente
        vel = new Vector2(Input.GetAxisRaw("Horizontal"), rb.velocity.y);

        // se pressionar direita retorna 1 , esquerda -1 , ou 0 se nao pressionar nada
        /*direction = Input.GetAxis("Horizontal");

        if (Input.GetKeyDown(KeyCode.Space))
        {
            rig.AddForce(Vector2.up * jumpForce, ForceMode2D.Impulse);
        }*/


    }

    //metodo atualização fixa
    private void FixedUpdate()
    {
        rb.velocity = vel;

        /*if (direction > 0)
        {
            transform.localScale = facingRight;
        }
        if (direction < 0)
        {
            transform.localScale = facingLeft;
        }
        rig.velocity = new Vector2(direction * speed, rig.velocity.y);*/
    }
}
