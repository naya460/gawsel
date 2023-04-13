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