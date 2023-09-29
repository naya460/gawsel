import { useState } from 'react'

import styles from './menu_narrow.module.css'
import Dropdown, { DropdownTitle } from './dropdown'
import GamesItem from './games_item'

export default function MenuNarrow(props: {className?: string | undefined}) {
	const [isOpen, setOpen] = useState(false);

	return (
    <div className={props.className}>
			<button
        className={styles.button}
        onClick={() => setOpen(!isOpen)}
        tabIndex={0}
      >
		    <span className="material-symbols-outlined" style={{width: 24}}>menu</span>
      </button>
      <Dropdown isOpen={isOpen} setOpen={setOpen}>
        <DropdownTitle>Games</DropdownTitle>
        <GamesItem isOpen={isOpen} />
      </Dropdown>
		</div>
	);
}
