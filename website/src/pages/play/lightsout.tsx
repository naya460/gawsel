import Head from 'next/head'

import Header from '@/components/website/header'
import ClossFade from '@/components/website/closs-fade'
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
        <Header />
        <ClossFade style={{padding: '1rem'}}>
          <LightsOutGame />
        </ClossFade>
      </main>
    </>
  )
}