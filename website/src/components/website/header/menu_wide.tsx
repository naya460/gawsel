import { useState } from 'react'
import Link from 'next/link'

import styles from './menu_wide.module.css'

export default function MenuWide(props: {className? : string | undefined}) {
  const [isGameMenuOpen, setGameMenuOpen] = useState(false);

	return (
		<div className={props.className}>
      <div
        className={styles.games}
        onClick={() => setGameMenuOpen(!isGameMenuOpen)}
      >
        Games
        <span className="material-symbols-outlined" style={{width: 24}}>expand_more</span>
		  </div>
      <div
        className={`${styles.background} ${!isGameMenuOpen && styles.background_hidden}`}
        onClick={() => setGameMenuOpen(false)}
      />
      <div
        className={`${styles.games_menu} ${!isGameMenuOpen && styles.games_menu_hidden}`}
        onClick={() => setGameMenuOpen(!isGameMenuOpen)}
      >
        <Link href="/play/minesweeper">Minesweeper</Link><br />
        <Link href="/play/lightsout">LightsOut</Link>
      </div>
		</div>
	);
}
