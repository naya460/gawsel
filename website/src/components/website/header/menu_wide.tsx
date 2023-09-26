import styles from './menu_wide.module.css'

export default function MenuWide(props: {className? : string | undefined}) {
	return (
		<div className={props.className}>
      <div className={styles.games}>
        Games
        <span className="material-symbols-outlined" style={{width: 24}}>expand_more</span>
		  </div>
		</div>
	);
}
