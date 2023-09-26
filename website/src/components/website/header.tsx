import Link from 'next/link'

import styles from './header.module.css'

export default function Header() {
	return (
    <div className={styles.variable}>
      <div className={styles.header}>
        <Link href="/" className={styles.title}><h1>GAWSEL Project</h1></Link>
        <div className={styles.header_spacer} />
        { /* when display is wide */ }
        <div className={`${styles.menu} ${styles.menu_wide}`}>
          <div className={styles.games}>
            Games
            <span className="material-symbols-outlined" style={{width: 24}}>expand_more</span>
          </div>
        </div>
        { /* when display is narrow */ }
        <div className={`${styles.menu} ${styles.menu_narrow}`}>
          <span className="material-symbols-outlined" style={{width: 24}}>menu</span>
        </div>
      </div>
      <div className={styles.spacer} />
    </div>
	);
}
