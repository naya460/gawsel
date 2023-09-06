import Head from 'next/head'

import MinesweeperGame from '../components/Minesweeper/MinesweeperGame/MinesweeperGame'
import LightsOut from '../components/LightsOut/LightsOutGame/LightsOutGame'

export default function Home() {
  return (
    <>
      <Head>
        <title>GAWSEL Project</title>
        <meta name="description" content="様々なゲームを、様々なプログラミング言語・ライブラリなどで実装する個人プロジェクト" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
      </Head>
      <main>
        <h1>GAWSEL Project</h1>
        <MinesweeperGame />
        <LightsOut />
      </main>
    </>
  )
}
