import Link from 'next/link'

import styles from './index.module.css'
import MenuWide from './menu_wide'
import MenuNarrow from './menu_narrow'

export default function Header() {
	return (
    <div className={styles.variable}>
      <div className={styles.header}>
        <Link href="/" className={styles.title} tabIndex={0}><h1>GAWSEL Project</h1></Link>
        <MenuWide className={`${styles.menu} ${styles.menu_wide}`}/>
        <MenuNarrow className={`${styles.menu} ${styles.menu_narrow}`} />
      </div>
      <div className={styles.spacer} />
    </div>
	);
}
