using UnityEngine;
using UnityEngine.SceneManagement;

public class Field : MonoBehaviour
{
    /// <summary>
    /// ボールがこの領域から出た時の処理
    /// </summary>
    public void OnTriggerExit2D()
    {
        // 今のシーンを終わらせてGameシーンを読み込む
        SceneManager.LoadScene("GameOver");
    }
}
