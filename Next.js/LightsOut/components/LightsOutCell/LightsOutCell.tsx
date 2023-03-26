import styles from "./LightsOutCell.module.css";

type Props = {
  isLightOn: boolean;
  onClick: () => void;
};

export default function LightsOutCell(props: Props) {
  return (
    <button
      className={`
        ${styles.cell}
        ${(props.isLightOn)? styles.cell_on : styles.cell_off}
      `}
      onClick={() => props.onClick()}
    />
  )
}