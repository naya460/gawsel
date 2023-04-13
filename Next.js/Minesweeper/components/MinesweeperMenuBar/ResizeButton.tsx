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

import react, {useState} from "react"

import styles from "./ResizeButton.module.css"

type Props = {
  setSize: (lx: number, ly: number, mine: number) => void;
}

export default function ResizeButton(props: Props): react.ReactElement {
  const [isPopupShown, setPopupShown] = useState(false);

  return(
    <>
      <div className={styles.resize_button_parent}>
        <button
          className={styles.resize_button}
          onClick={() => setPopupShown(!isPopupShown)}
        >
          <div className={styles.resize_button_contents}>
            <div className={styles.size_text}>Size</div>
            <div className={styles.v_text}>v</div>
          </div>
        </button>
        {
          function () {
            if (isPopupShown) {
              return (
                <ResizePopup
                  setSize={(lx: number, ly: number, mine: number) => {
                    props.setSize(lx, ly, mine);
                    setPopupShown(false);
                  }}
                />
              );
            }
          }()       
        }
      </div>
    </>
  );
}

function ResizePopup(props: Props): react.ReactElement {
  return(
    <>
      <div className={styles.resize_popup}>
        <div style={{'display': 'flex', 'flexDirection': 'column'}}>
          <button
            className={styles.size_button}
            onClick={() => props.setSize(9, 9, 10)}
          >9 x 9  :  10</button>
          <button
            className={styles.size_button}
            onClick={() => props.setSize(16, 16, 40)}
          >16 x 16  :  40</button>
          <button
            className={styles.size_button}
            onClick={() => props.setSize(30, 16, 99)}
          >30 x 16  :  99</button>
        </div>
      </div>
    </>
  )
}