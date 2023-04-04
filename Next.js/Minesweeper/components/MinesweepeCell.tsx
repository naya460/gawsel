import react from "react"

import styles from "./MinesweeperCell.module.css"

export default function MinesweeperCell(): react.ReactElement {
    return (
        <button className={styles.cell} />
    );
}