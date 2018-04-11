using UnityEngine;

/// <summary>
/// ブロックに関する処理
/// </summary>
public class Block : MonoBehaviour
{
    /// <summary>
    /// ボールがぶつかったときの処理
    /// </summary>
    void OnCollisionExit2D()
    {
        // ブロックのGameObjectを消す
        Destroy(gameObject);
    }
}