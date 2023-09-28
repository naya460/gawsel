import styles from './dropdown.module.css'

import Link from 'next/link'

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
        tabindex={-1}
      >
        {props.children}
      </div>
    </>
	);
}

export function DropdownItem(
  props: {
    href: string,
    isOpen: boolean,
    children?: JSX.Element | undefined
  }) {
  return (
    <div className={styles.item}>
      <Link
        href={props.href}
        tabindex={(props.isOpen)? 0 : -1}
      >
        {props.children}
        <div className={styles.spacer} />
        <span class="material-symbols-outlined">navigate_next</span>
      </Link>
    </div>
  );
}

export function DropdownTitle(props: {children?: JSX.Element | undefined}) {
  return(
    <div className={styles.item_title}>
      {props.children}
      <div />
    </div>
  );
}
