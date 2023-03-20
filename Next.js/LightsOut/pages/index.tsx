import styles from "./LightsOut.module.css";

const LightsOutCell = () => {
  return (
    <button className={styles.LightsOutCell} />
  )
}

export default function IndexPage() {
  return (
    <div>
      <LightsOutCell />
    </div>
  )
}
