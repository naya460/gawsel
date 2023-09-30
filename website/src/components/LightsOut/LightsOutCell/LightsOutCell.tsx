/*
  Copyright 2023 naya460

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

import styles from "./LightsOutCell.module.css";

type Props = {
  isLightOn: boolean;
  onClick: () => void;
};

export default function LightsOutCell(props: Props) {
  return (
    <button
      className={`
        ${styles.cell}
        ${(props.isLightOn)? styles.cell_on : styles.cell_off}
      `}
      onClick={() => props.onClick()}
    />
  )
}