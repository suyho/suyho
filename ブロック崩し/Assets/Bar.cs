using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class Bar : MonoBehaviour {

    public void OnTouch(BaseEventData arg)
    {
        // EventTriggerでは汎用の為BaseEventDataですが、ドラッグのイベントでは実態はPointerEventDataなのでキャストしてあげる
        PointerEventData e = arg as PointerEventData;
        var transform = GetComponent<RectTransform>();
        var position = transform.position; // 今のtransformの座標を取得
        position.x = e.position.x;         // ドラッグされている場所を代入
        transform.position = position;     // transformに座標を反映
    }
    void Update()
    {

    }
}
