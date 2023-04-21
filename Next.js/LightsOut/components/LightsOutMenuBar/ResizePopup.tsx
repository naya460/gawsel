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

import React from "react"

import styles from "./ResizePopup.module.css";

type Props = {
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
    <div className={styles.resize_popup}>
      {SizeList()}
      <button
        className={styles.close_button}
        onClick={() => props.onClose()}
      >Close</button>
    </div>
  );
}