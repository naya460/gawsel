import { useState } from 'react'

import styles from './menu_wide.module.css'
import Dropdown, { DropdownItem } from './dropdown'
import GamesItem from './games_item'

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
      <Dropdown isOpen={isGameMenuOpen} setOpen={setGameMenuOpen}>
        <GamesItem isOpen={isGameMenuOpen} />
      </Dropdown>
		</div>
	);
}
