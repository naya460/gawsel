import React, {useState} from "react"

import styles from "./LightsOutMenuBar.module.css";

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
          <button className={styles.size_button} onClick={() => handleResize(length)}>{length}x{length}</button>
      )
      }
      return <div>{list}</div>;
  }

  return (
      <div>
      <div className={styles.popup_parent}>
          <button
          className={styles.resize_button}
          onClick={() => handleResizeButtonClick()}
          >
          Size<br />{props.length}x{props.length}
          </button>
          <div className={`
          ${styles.resize_popup}
          ${isPopupShown && styles.popup_shown}
          `}>
          {SizeList()}
          <button className={styles.close_button} onClick={() => handleCloseResizePopup()}>Close</button>
          </div>
      </div>
      </div>
  )
}

type Props = {
  length: number;
  onRandomize: () => void;
  onResize: (length: number) => void;
}

export default function LightsOutMenuBar(props: Props) {
  return (
    <div className={styles.menu_bar}>
      <button
        className={styles.new_game_button}
        onClick={() => props.onRandomize()}
      >New Game</button>
      <ResizeButton onClick={(length) => props.onResize(length)} length={props.length} />
    </div>
  )
}