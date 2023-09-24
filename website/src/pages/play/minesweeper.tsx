import Head from 'next/head'

import Header from '@/components/website/header'
import ClossFade from '@/components/website/closs-fade'
import MinesweeperGame from '@/components/Minesweeper/MinesweeperGame/MinesweeperGame'

export default function Minesweeper() {
  return (
    <>
      <Head>
        <title>Play : Minesweeper | GAWSEL Project</title>
        <meta name="description" content="ブラウザでマインスイーパーを遊ぶ" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
      </Head>
      <main>
        <Header />
        <ClossFade>
          <MinesweeperGame />
        </ClossFade>
      </main>
    </>
  )
}