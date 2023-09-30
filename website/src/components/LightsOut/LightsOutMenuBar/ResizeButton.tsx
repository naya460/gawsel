/*
  Copyright 2023 naya460

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

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