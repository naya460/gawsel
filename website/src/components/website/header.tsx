import Link from 'next/link'

import styles from './header.module.css'

export default function Header() {
	return (
    <div className={styles.variable}>
      <div className={styles.header}>
        <Link href="/" className={styles.title}><h1>GAWSEL Project</h1></Link>
      </div>
      <div className={styles.spacer} />
    </div>
	);
}
