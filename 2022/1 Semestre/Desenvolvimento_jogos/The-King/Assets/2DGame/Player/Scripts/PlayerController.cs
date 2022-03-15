using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public Rigidbody2D rig;

    public float speed;
    public float jumpForce;
    private float direction;

    private Vector3 facingRight;
    private Vector3 facingLeft;

    public bool inSolo;
    public Transform detectSolo;
    public LayerMask isSolo;

    // Start is called before the first frame update
    void Start()
    {
        facingRight = transform.localScale;
        facingLeft = transform.localScale;
        facingLeft.x = facingLeft.x * -1;

        rig = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {

        inSolo = Physics2D.OverlapCircle(detectSolo.position, 0.2f, isSolo);

        // se pressionar direita retorna 1 , esquerda -1 , ou 0 se nao pressionar nada
        direction = Input.GetAxis("Horizontal");

        if (Input.GetKeyDown(KeyCode.Space) && inSolo == true)
        {
            rig.AddForce(Vector2.up * jumpForce, ForceMode2D.Impulse);
        }


    }

    private void FixedUpdate()
    {
        if (direction > 0)
        {
            transform.localScale = facingRight;
        }
        if (direction < 0)
        {
            transform.localScale = facingLeft;
        }
        rig.velocity = new Vector2(direction * speed, rig.velocity.y);
    }
}
