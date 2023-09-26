import { Html, Head, Main, NextScript } from 'next/document'

export default function Document() {
  return (
    <Html lang="ja">
      <Head>
        <link
          rel="stylesheet"
          href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200&display=block"
        />
      </Head>
      <body style={{margin: 0, backgroundColor: "#f0f0f0"}}>
        <Main />
        <NextScript />
      </body>
    </Html>
  )
}
