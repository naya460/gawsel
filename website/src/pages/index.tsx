import Head from 'next/head'
import Link from 'next/link'

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
        <p>GAWSEL Project は naya460 が個人で開発しているプロジェクトです。</p>
        <p>様々な言語やフレームワークなどを用いて、ミニゲームを作成しています。</p>
        <p>このサイトでは、ウェブ上で遊べるものを公開しています。</p>
        <p><Link href="/play/minesweeper">Minesweeper</Link></p>
        <p><Link href="/play/lightsout">LightsOut</Link></p>
      </main>
    </>
  )
}
