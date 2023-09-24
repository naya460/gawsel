import type { AppProps } from 'next/app'
import { AnimatePresence } from 'framer-motion'
import { motion } from 'framer-motion'

export default function App({ Component, pageProps }: AppProps) {
  return (
    <AnimatePresence mode="wait">
      
      <motion.div
          initial={{opacity: "0%"}}
          animate={{opacity: "100%"}}
          exit={{opacity: "0%"}}
        >
        <Component {...pageProps} />
      </motion.div>
    </AnimatePresence>
  );
}
