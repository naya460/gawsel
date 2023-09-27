import { useState } from 'react'
import Link from 'next/link'

import styles from './menu_wide.module.css'
import Dropdown from './dropdown'

export default function MenuWide(props: {className? : string | undefined}) {
  const [isGameMenuOpen, setGameMenuOpen] = useState(false);

	return (
		<div className={props.className}>
      <button
        className={styles.games}
        onClick={() => setGameMenuOpen(!isGameMenuOpen)}
        tabindex={0}
      >
        Games
        <span className="material-symbols-outlined" style={{width: 24}}>expand_more</span>
		  </button>
      <Dropdown
        isOpen={isGameMenuOpen}
        setOpen={setGameMenuOpen}
      >
        <Link href="/play/minesweeper" tabindex={(isGameMenuOpen)? 0 : -1}>Minesweeper</Link><br />
        <Link href="/play/lightsout" tabindex={(isGameMenuOpen)? 0 : -1}>LightsOut</Link>
      </Dropdown>
		</div>
	);
}
