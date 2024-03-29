import Head from 'next/head'
import Link from 'next/link'

import Header from '@/components/website/header'
import ClossFade from '@/components/website/closs-fade'
import styles from './index.module.css'

export default function Home() {
  return (
    <>
      <Head>
        <title>GAWSEL Project</title>
        <meta name="description" content="様々なゲームを、様々なプログラミング言語・ライブラリなどで実装する個人プロジェクト" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
      </Head>
      <main>
        <Header />
        <ClossFade>
          <div className={styles.contents}>
            <p>
              <Link href="https://github.com/naya460/gawsel">GAWSEL Project</Link> は <Link href="https://github.com/naya460">naya460</Link> が個人で開発しているプロジェクトです。</p>
            <p>様々な言語やフレームワークなどを用いて、ミニゲームを作成しています。</p>
            <p>このサイトでは、ウェブ上で遊べるものを公開しています。</p>
            <div className={styles.game_list}>
              <GameButton title="Minesweeper" href="/play/minesweeper">
                爆弾以外のマスを全て開ける定番ゲームです。目印に旗を置きながら遊ぶことができます。
              </GameButton>
              <GameButton title="LightsOut" href="/play/lightsout" >
                全てのライトを全て消灯させるゲームです。押したライトと上下左右が反転します。
              </GameButton>
            </div>
          </div>
        </ClossFade>
      </main>
    </>
  )
}

function GameButton(props: {href: string, title: string, children?: string}) {
  return (
    <>
      <Link href={props.href} className={styles.game_button} tabIndex={0}>
        <div>
          <div className="title">{props.title}</div>
          <div>{props.children}</div>
        </div>
      </Link>
    </>
  )
}