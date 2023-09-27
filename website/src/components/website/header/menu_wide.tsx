import { useState } from 'react'
import Link from 'next/link'

import styles from './menu_wide.module.css'
import Dropdown from './dropdown'

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
      <Dropdown
        isOpen={isGameMenuOpen}
        setOpen={setGameMenuOpen}
      >
        <Link href="/play/minesweeper">Minesweeper</Link><br />
        <Link href="/play/lightsout">LightsOut</Link>
      </Dropdown>
		</div>
	);
}
