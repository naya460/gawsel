import { DropdownItem } from './dropdown'

export default function GamesItem(props: {isOpen: boolean}) {
	return (
    <>
      <DropdownItem href="/play/minesweeper" isOpen={props.isOpen}>Minesweeper</DropdownItem>
      <DropdownItem href="/play/lightsout" isOpen={props.isOpen}>LightsOut</DropdownItem>
    </>
	);
}

