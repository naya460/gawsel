import React, {useState} from "react"

import styles from "../pages/LightsOut.module.css";

const ResizeButton = (props) => {
  const [isPopupShown, setPopupShown] = useState(false);

  const handleResizeButtonClick = () => {
      if (isPopupShown) {
      setPopupShown(false);
      } else {
      setPopupShown(true);
      }
  }

  const handleCloseResizePopup = () => {
      setPopupShown(false);
  }

  const handleResize = (length) => {
      props.onClick(length);
      handleCloseResizePopup();
  }

  const SizeList = () => {
      let list = [];
      for (let i = 0; i < 8; i++) {
      let length = i + 3;
      list.push(
          <button className={styles.LightsOutSizeButton} onClick={() => handleResize(length)}>{length}x{length}</button>
      )
      }
      return <div>{list}</div>;
  }

  return (
      <div>
      <div className={styles.LightsOutResizePopupParent}>
          <button
          className={styles.LightsOutResizeButton}
          onClick={() => handleResizeButtonClick()}
          >
          Size<br />{props.length}x{props.length}
          </button>
          <div className={`
          ${styles.LightsOutResizePopup}
          ${isPopupShown && styles.LightsOutResizePopupShown}
          `}>
          {SizeList()}
          <button className={styles.LightsOutCloseButton} onClick={() => handleCloseResizePopup()}>Close</button>
          </div>
      </div>
      </div>
  )
}

type Props = {
  length: number;
  handleRandomize: () => void;
  handleResize: (length: number) => void;
}

export default function LightsOutMenuBar(props: Props) {
  return (
    <div className={styles.LightsOutMenuBar}>
      <button
        className={styles.LightsOutNewGameButton}
        onClick={() => props.handleRandomize()}
      >New Game</button>
      <ResizeButton onClick={(length) => props.handleResize(length)} length={props.length} />
    </div>
  )
}