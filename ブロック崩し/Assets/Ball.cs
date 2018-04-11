using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour {

    // Use this for initialization
    void Start()
    {
        // このGameObjectに付与されている物理演算コンポネントを取得
        var body = gameObject.GetComponent<Rigidbody2D>();
        // 画面描画用のCanvasを取得
        var canvas = GetComponentInParent<Canvas>();

        // ボールを動かす向き：とりあえず右上
        // normalized(正規化)で大きさを1のベクトルに
        var direction = new Vector2(1, 1).normalized;

        // velocity(速度)を設定する。
        // この速さは秒速。上でdirectionの大きさは1にしているので1*640=640が速さになる
        body.velocity = direction * 640 * canvas.transform.localScale.x;
    }
    void Update()
    {

    }
}
