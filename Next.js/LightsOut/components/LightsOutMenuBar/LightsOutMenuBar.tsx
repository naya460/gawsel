import React, {useState} from "react"

import styles from "./LightsOutMenuBar.module.css";

import ResizePopup from "./ResizePopup"

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

  return (
    <div className={styles.popup_parent}>
      <button
        className={styles.resize_button}
        onClick={() => handleResizeButtonClick()}
      >Size<br />{props.length}x{props.length}
      </button>
      <ResizePopup
        className={`${styles.resize_popup} ${isPopupShown && styles.popup_shown}`}
        onResize={(length) => handleResize(length)}
        onClose={() => handleCloseResizePopup()}
      />
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