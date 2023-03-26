import React from "react"

import styles from "./ResizePopup.module.css";

type Props = {
  className?: string;
  onResize: (length: number) => void;
  onClose: () => void;
}

export default function ResizePopup(props: Props) {
  // サイズ選択ボタンの一覧を作成
  const SizeList = () => {
    let list = [];
    for (let i = 0; i < 8; i++) {
      let length = i + 3;
      list.push(
        <button
          key={length}
          className={styles.size_button}
          onClick={() => props.onResize(length)}
        >{length}x{length}</button>
      )
    }
    return <div>{list}</div>;
  }

  return (
    <div className={`${styles.resize_popup} ${props.className}`}>
      {SizeList()}
      <button
        className={styles.close_button}
        onClick={() => props.onClose()}
      >Close</button>
    </div>
  );
}