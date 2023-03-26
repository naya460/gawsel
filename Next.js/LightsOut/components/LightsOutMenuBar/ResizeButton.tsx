import React, {useState} from "react"

import styles from "./ResizeButton.module.css"

import ResizePopup from "./ResizePopup"

type Props = {
  length: number;
  onClick: (length: number) => void;
}

export default function ResizeButton(props: Props) {
  const [isPopupShown, setPopupShown] = useState(false);

  // リサイズボタンを押したときの処理
  // ポップアップの表示を切り替える
  const handleResizeButtonClick = () => {
    if (isPopupShown) {
      setPopupShown(false);
    } else {
      setPopupShown(true);
    }
  }

  // ポップアップを閉じる処理
  const handleCloseResizePopup = () => {
      setPopupShown(false);
  }

  // 盤面のサイズを変える処理
  const handleResize = (length: number) => {
      props.onClick(length);
      handleCloseResizePopup();
  }

  return (
    <div className={styles.popup_parent}>
      <button
        className={styles.resize_button}
        onClick={() => handleResizeButtonClick()}
      >Size<br />{props.length}x{props.length}
      </button>
      {
        function () {
          if (isPopupShown) {
            return (
              <ResizePopup
                onResize={(length) => handleResize(length)}
                onClose={() => handleCloseResizePopup()}
              />
            )
          } else {
            return <></>
          }
        }()
      }
      
    </div>
  )
}