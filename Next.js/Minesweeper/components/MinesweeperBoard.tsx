import react from "react"

import MinesweeperCell from "./MinesweeperCell"

export default function(): react.ReactElement {
  return (
    <>
      <div>
        {
          function (): react.ReactElement {
            const list = [];
            for (let i = 0; i < 9; i++) {
              const line = [];
              for (let j = 0; j < 9; j++) {
                line.push(<MinesweeperCell />);
              }
              list.push(<div>{line}</div>);
            }
            return <>{list}</>;
          }()
        }
      </div>
    </>
  );
}