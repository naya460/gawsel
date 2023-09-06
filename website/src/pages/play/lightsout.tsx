import Head from 'next/head'

import LightsOutGame from '@/components/LightsOut/LightsOutGame/LightsOutGame'

export default function Minesweeper() {
  return (
    <>
      <Head>
        <title>Play : LightsOut | GAWSEL Project</title>
        <meta name="description" content="ブラウザでライツアウトを遊ぶ" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
      </Head>
      <main>
        <h1>GAWSEL Project</h1>
        <LightsOutGame />
      </main>
    </>
  )
}