import react, {useState} from "react"

import styles from "./ResizeButton.module.css"

export default function ResizeButton(): react.ReactElement {
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
              return (<ResizePopup />);
            }
          }()       
        }
      </div>
    </>
  );
}

function ResizePopup(): react.ReactElement {
  return(
    <>
      <div className={styles.resize_popup}>

      </div>
    </>
  )
}