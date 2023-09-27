import styles from './dropdown.module.css'

interface Props {
  isOpen: boolen;
  setOpen: (isOpen: boolean) => void;
  children?: JSX.Element | undefine;
}

export default function Dropdown(props: Props) {
	return (
    <>
      <div
        className={`${styles.background} ${!props.isOpen && styles.background_hidden}`}
        onClick={() => props.setOpen(false)}
      />
      <div
        className={`${styles.menu} ${!props.isOpen && styles.menu_hidden}`}
        onClick={() => props.setOpen(!props.isOpen)}
      >
        {props.children}
      </div>
    </>
	);
}