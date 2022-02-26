<?xml version="1.0" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<!-- Version: $Id: pawndoc.xsl 3612 2006-07-22 09:59:46Z thiadmer $ -->

<xsl:template match="/">
<HTML>
<HEAD>
<META http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<TITLE><xsl:value-of select="doc/assembly/name" /></TITLE>
<STYLE type="text/css">
	BODY { FONT-FAMILY: "Verdana", sans-serif; FONT-SIZE: x-small; }
	CODE { FONT-SIZE: small; }
	DL { MARGIN-LEFT: 4em; DISPLAY: compact }
	DT { FONT-WEIGHT: bold }
	A:link { COLOR: #4e4887 }
	A:visited { COLOR: #8080c8 }
	A:active { COLOR: #f16043 }
	A:hover { COLOR: #f16043 }
	P { MARGIN-BOTTOM: 0.5em; MARGIN-TOP: 0.5em; MARGIN-LEFT: 4em }
	P.noindent { MARGIN-LEFT: 0em }
	P.syntax { FONT-WEIGHT: bold }
	HR.para { HEIGHT: 0; BORDER: 0; COLOR: transparent; BACKGROUND-COLOR: transparent; MARGIN-TOP: 0.5em; MARGIN-BOTTOM: 0; }
	XMP { BACKGROUND-COLOR: #ddeeff; FONT-SIZE: x-small; MARGIN: 1em }
	PRE { BACKGROUND-COLOR: #ddeeff; FONT-SIZE: x-small; MARGIN: 1em }
	TABLE { BORDER-BOTTOM: medium none; BORDER-LEFT: medium none; BORDER-RIGHT: medium none; BORDER-TOP: medium none }
	TABLE.param { BACKGROUND-COLOR: #ddeeff; }
	TABLE.transition { BACKGROUND-COLOR: #ddeeff; }
	TD { BACKGROUND-COLOR: #ddeeff; BORDER-BOTTOM: medium none; BORDER-LEFT: medium none; BORDER-RIGHT: medium none; BORDER-TOP: medium none; FONT-SIZE: x-small; MARGIN: 2px; PADDING-BOTTOM: 2px; PADDING-LEFT: 2px; PADDING-RIGHT: 2px; PADDING-TOP: 2px; TEXT-ALIGN: left }
	TD.header { BACKGROUND-COLOR: transparent; FONT-WEIGHT: bold; COLOR: #4e4887; WIDTH: 3.3em; PADDING-LEFT: 0px; MARGIN-BOTTOM: 0.5em }
	TD.inline { BACKGROUND-COLOR: transparent }
	TD.param { FONT-WEIGHT: bold; FONT-STYLE: italic; PADDING-RIGHT: 20px; }
	TD.transition { PADDING-RIGHT: 10px; }
	TH { BACKGROUND-COLOR: #336699; COLOR: #ddeeff; BORDER-BOTTOM: medium none; BORDER-LEFT: medium none; BORDER-RIGHT: medium none; BORDER-TOP: medium none; FONT-SIZE: x-small; MARGIN: 2px; PADDING-BOTTOM: 2px; PADDING-LEFT: 4px; PADDING-RIGHT: 4px; PADDING-TOP: 2px; TEXT-ALIGN: left }
	UL { MARGIN-TOP: 0.5em; }
	LI.referrer { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.dependency { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.seealso { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.attribute { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.post { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.author { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.fixes { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.see { DISPLAY: inline; PADDING-RIGHT: 8px }
	LI.changelog { DISPLAY: inline; }
	.symbol { PADDING-RIGHT: 8px }
	OL { MARGIN-TOP: 0.5em; }
	SPAN.paraminfo { FONT-WEIGHT:Bold; COLOR: #336699; }
	H1 { COLOR: #4e4887; FONT-SIZE: x-large; MARGIN-BOTTOM: 0.5em; MARGIN-TOP: 1em; PADDING-LEFT: 4px }
	H2 { BORDER-RIGHT: #4e4887 8px solid; BORDER-TOP: #4e4887 2px solid; COLOR: #4e4887; MARGIN-BOTTOM: 0.5em; MARGIN-TOP: 1em; }
	H2.general { BORDER: none; }
	H3 { COLOR: #4e4887; FONT-SIZE: x-small; MARGIN-BOTTOM: 0.5em }
	H4 { COLOR: #4e4887; FONT-SIZE: x-small; FONT-STYLE: italic; MARGIN-BOTTOM: 0.5em; DISPLAY: inline; MARGIN: 50px 8px 0px 0px }
	H5 { COLOR: #4e4887; FONT-SIZE: xx-small; MARGIN-BOTTOM: 0.5em }
	H6 { COLOR: #4e4887; FONT-SIZE: xx-small; FONT-STYLE: italic; MARGIN-BOTTOM: 0.5em }
	DIV.library { TEXT-ALIGN: center; BORDER-RIGHT: #4e4887 8px solid; BORDER-TOP: #4e4887 2px solid; COLOR: #4e4887; MARGIN-BOTTOM: 0.5em; MARGIN-TOP: 1em; }
	H1.library { TEXT-ALIGN: center; COLOR: #4e4887; MARGIN-TOP: 0.3em; }
	H2.library { TEXT-ALIGN: center; BORDER: none; }
	PRE { BACKGROUND-COLOR: #ddeeff; FONT-SIZE: small; MARGIN: 1em }
</STYLE>
</HEAD>
<BODY>
	<!-- <h1><xsl:value-of select="doc/assembly/name" /></h1> -->
	<xsl:apply-templates select="/doc/general" />

	<br />## Enums<br />
	<xsl:apply-templates select="/doc/members/member" mode="rest">
		<xsl:with-param name="type" select="'T:'" />
	</xsl:apply-templates>

	<br />## Constants<br />
	<xsl:apply-templates select="/doc/members/member" mode="rest">
		<xsl:with-param name="type" select="'C:'" />
	</xsl:apply-templates>
	
	<br />## Variables<br />
	<xsl:apply-templates select="/doc/members/member" mode="rest">
		<xsl:with-param name="type" select="'F:'" />
	</xsl:apply-templates>
	
	<br />## Functions<br />
	<xsl:apply-templates select="/doc/members/member" mode="rest">
		<xsl:with-param name="type" select="'M:'" />
	</xsl:apply-templates>
</BODY>
</HTML>
</xsl:template>

<xsl:template match="general">
    <xsl:apply-templates />
    <br />
</xsl:template>

<xsl:template match="member[library]" mode="library">
	<xsl:param name="library" />
	<xsl:param name="type" />
	<xsl:if test="library = $library">
		<xsl:apply-templates select="." mode="full">
			<xsl:with-param name="type" select="$type" />
		</xsl:apply-templates>
	</xsl:if>
</xsl:template>

<xsl:template match="member[not(library)]" mode="library">
</xsl:template>

<!-- Clean up the rest of the members that have no "library" specifier -->
<xsl:template match="member[library]" mode="rest">
</xsl:template>

<xsl:template match="member[not(library)]" mode="rest">
	<xsl:param name="type" />
	<xsl:apply-templates select="." mode="full">
		<xsl:with-param name="type" select="$type" />
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="member" mode="full">
	<xsl:param name="type" />
	<xsl:if test="substring(@name,1,2) = $type">
		<xsl:choose>
			<xsl:when test="substring(@name,1,2) = 'T:'">
				<br />### `<xsl:value-of select="substring(@name,3)" />`:<br />
				<xsl:apply-templates select="summary" />
				<xsl:if test="remarks">
					<br />#### Remarks<br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:if test="member">
					<br />#### Members<br />
					<blockquote>
					<xsl:apply-templates select="member" mode="submember" />
					</blockquote>
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br />#### Used by<br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br />#### Fixes<br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br />#### Depends on<br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="seealso">
					<br />#### See Also<br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</xsl:when>
			<xsl:when test="substring(@name,1,2) = 'C:'">
				<br />### `<xsl:value-of select="substring(@name,3)" />`:<br /><br />
				| **Value** | `<xsl:value-of select="@value" />:` |<br />
				<xsl:apply-templates select="summary" />
				<xsl:apply-templates select="tagname" />
				<xsl:apply-templates select="size" />
				<xsl:if test="remarks">
					<br />#### Remarks<br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br />#### Used by<br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br />#### Fixes<br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br />#### Depends on<br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="seealso">
					<br />#### See Also<br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</xsl:when>
			<xsl:when test="substring(@name,1,2) = 'M:'">
				<br />### `<xsl:value-of select="substring(@name,3)" />`:<br />
				<xsl:apply-templates select="summary" />
				<br />#### Syntax<br /><br />```pawn<br /><xsl:value-of select="@syntax" /><br />```<br />
				<xsl:if test="param">
					<br /><xsl:apply-templates select="param" /><br />
				</xsl:if>
				<xsl:apply-templates select="tagname" />
				<xsl:apply-templates select="returns" />
				<xsl:if test="remarks">
					<br />#### Remarks<br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br />#### Used by<br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br />#### Fixes<br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br />#### Depends on<br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="attribute">
					<br />#### Attributes<br />
					<br /><xsl:apply-templates select="attribute" /><br />
				</xsl:if>
				<xsl:apply-templates select="automaton" />
				<xsl:if test="transition">
					<br />#### Transition table<br />
					<br />
						<table class="transition">
							<tr><th>Source</th><th>Target</th><th>Condition</th></tr>
							<xsl:apply-templates select="transition" />
						</table>
					<br />
				</xsl:if>
				<xsl:apply-templates select="stacksize" />
				<xsl:if test="seealso">
					<br />#### See Also<br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</xsl:when>
			<xsl:when test="substring(@name,1,6) = 'F:FIX_'">
				<!-- This does nothing, just hides fixes from variables -->
			</xsl:when>
			<xsl:when test="substring(@name,1,2) = 'F:'">
				<br />### `<xsl:value-of select="substring(@name,3)" />`:<br />
				<xsl:apply-templates select="summary" />
				<xsl:apply-templates select="tagname" />
				<xsl:if test="remarks">
					<br />#### Remarks<br />
					<xsl:apply-templates select="remarks" />
				</xsl:if>
				<xsl:apply-templates select="example" />
				<xsl:if test="referrer">
					<br />#### Used by<br />
					<br /><xsl:apply-templates select="referrer" /><br />
				</xsl:if>
				<xsl:if test="fixes">
					<br />#### Fixes<br />
					<br /><xsl:apply-templates select="fixes" /><br />
				</xsl:if>
				<xsl:if test="dependency">
					<br />#### Depends on<br />
					<br /><xsl:apply-templates select="dependency" /><br />
				</xsl:if>
				<xsl:if test="seealso">
					<br />#### See Also<br />
					<br /><xsl:apply-templates select="seealso" /><br />
				</xsl:if>
			</xsl:when>
		</xsl:choose>
	</xsl:if>
</xsl:template>

<!-- Show the list of fixes first -->
<xsl:template match="member" mode="fixes">
	<xsl:choose>
		<xsl:when test="substring(@name,1,6) = 'F:FIX_'">
			<br />### <xsl:value-of select="substring(@name,7)" />:<br />
			<xsl:apply-templates select="fix" />
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template match="member" mode="submember">
	<xsl:choose>
		<xsl:when test="substring(@name,1,2) = 'C:'">
			* `<xsl:value-of select="substring(@name,3)" /> = <xsl:value-of select="@value" />`<br />
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template match="summary">
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="param">
	| `<xsl:value-of select="@name" />` | <xsl:apply-templates /> |<br />
</xsl:template>

<xsl:template match="paraminfo">
	`<xsl:apply-templates />`
</xsl:template>

<xsl:template match="tagname">
	| **Tag** | `<xsl:value-of select="@value" />:` |<br />
</xsl:template>

<xsl:template match="size">
	| **Size** | `<xsl:value-of select="@value" />:` |<br />
</xsl:template>

<xsl:template match="returns">
	<br />#### Returns<br />
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="remarks">
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="example">
	<br />#### Example<br />
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="attribute">
	* `<xsl:value-of select="@name" /><br />`
</xsl:template>

<xsl:template match="referrer">
	* [`<xsl:value-of select="@name" />`](#<xsl:value-of select="@name" />)<br />
</xsl:template>

<xsl:template match="dependency">
	* [`<xsl:value-of select="@name" />`](#<xsl:value-of select="@name" />)<br />
</xsl:template>

<xsl:template match="stacksize">
	<br />#### Estimated stack usage <br />
	<br /><xsl:value-of select="@value" /> cells<br />
</xsl:template>

<xsl:template match="automaton">
	<br />#### Automaton<br />
	<br /><xsl:value-of select="@name" /><br />
</xsl:template>

<xsl:template match="transition">
	<tr>
		<td class="transition"><xsl:value-of select="@source" /></td>
		<td class="transition"><xsl:value-of select="@target" /></td>
		<td><xsl:value-of select="@condition" /></td>
	</tr>
</xsl:template>

<xsl:template match="code">
	<br />```pawn<br /><xsl:apply-templates /><br />```<br />
</xsl:template>

<xsl:template match="seealso">
	* [`<xsl:value-of select="@name" />`](#<xsl:value-of select="@name" />)<br />
</xsl:template>

<xsl:template match="paramref">
	<i><xsl:value-of select="@name" /></i>
</xsl:template>

<xsl:template match="c">`<xsl:apply-templates />`</xsl:template>

<xsl:template match="em">*<xsl:apply-templates />*</xsl:template>

<xsl:template match="ul"><br /><xsl:apply-templates /><br /></xsl:template>

<xsl:template match="ol">* <xsl:apply-templates /><br /></xsl:template>

<xsl:template match="li">* <xsl:apply-templates /><br /></xsl:template>

<xsl:template match="p"><br /><xsl:apply-templates /><br /></xsl:template>

<xsl:template match="para"><br /><xsl:apply-templates /><br /></xsl:template>

<xsl:template match="section"><br />## <xsl:apply-templates /><br /></xsl:template>

<xsl:template match="subsection"><br />### <xsl:apply-templates /><br /></xsl:template>

<xsl:template match="library">
	<br /><br />__________________________________________<br /><br />

	<xsl:value-of select="@name" /><br />
	==========================================<br />
	<xsl:if test="@description">
		<br /><xsl:value-of select="@description" /><br />
		------------------------------------------<br />
	</xsl:if>
	<br /><xsl:apply-templates /><br />
	<xsl:if test="@name = 'fixes.inc'">
		<br />## Fixes<br />
		<xsl:apply-templates select="/doc/members/member" mode="fixes" />
	</xsl:if>
	
	<br />## Enums<br />
	<xsl:apply-templates select="/doc/members/member" mode="library">
		<xsl:with-param name="library" select="@name" />
		<xsl:with-param name="type" select="'T:'" />
	</xsl:apply-templates>

	<br />## Constants<br />
	<xsl:apply-templates select="/doc/members/member" mode="library">
		<xsl:with-param name="library" select="@name" />
		<xsl:with-param name="type" select="'C:'" />
	</xsl:apply-templates>
	
	<br />## Variables<br />
	<xsl:apply-templates select="/doc/members/member" mode="library">
		<xsl:with-param name="library" select="@name" />
		<xsl:with-param name="type" select="'F:'" />
	</xsl:apply-templates>
	
	<br />## Functions<br />
	<xsl:apply-templates select="/doc/members/member" mode="library">
		<xsl:with-param name="library" select="@name" />
		<xsl:with-param name="type" select="'M:'" />
	</xsl:apply-templates>

	<br /><br />__________________________________________<br /><br />
</xsl:template>

<xsl:template match="br"><br /></xsl:template>
<xsl:template match="indent">&#160;&#160;&#160;&#160;</xsl:template>

<xsl:template match="a">
	<xsl:choose>
		<xsl:when test="node()">[<xsl:apply-templates />](<xsl:value-of select="@href" />)</xsl:when>
		<xsl:otherwise>[<xsl:value-of select="@href" />](<xsl:value-of select="@href" />)</xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="symbolref">
	[`<xsl:value-of select="@name" />`](#<xsl:value-of select="@name" />)
</xsl:template>

<xsl:template match="symbol">
	* [`<xsl:value-of select="@name" />`](#<xsl:value-of select="@name" />):&#160;<xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="synonym">
	* `<xsl:value-of select="@name" />`: Synonym for `<xsl:value-of select="@for" />`<xsl:apply-templates />.<br />
</xsl:template>

<xsl:template match="changelog">
	<br />#### <xsl:value-of select="@date" /><br />
	<xsl:apply-templates />
</xsl:template>


<!-- fixes.inc -->

<xsl:template match="fix">
	<xsl:if test="@fixed">
		<br />**Fixed in <xsl:value-of select="@fixed" />**<br />
	</xsl:if>
	<xsl:if test="@disabled">
		<xsl:if test="@disabled='true'">
			<br />**Disabled By Default**<br />
		</xsl:if>
	</xsl:if>

	<br />#### Problem<br />
	<xsl:apply-templates select="problem" />
	<br />#### Solution<br />
	<xsl:apply-templates select="solution" />
	<xsl:if test="see">
		<br />#### See<br />
		<br /><xsl:apply-templates select="see" /><br />
	</xsl:if>
	<xsl:if test="author">
		<br />#### Author(s)<br />
		<br /><xsl:apply-templates select="author" /><br />
	</xsl:if>
	<xsl:if test="post">
		<br />#### Post(s)<br />
		<br /><xsl:apply-templates select="post" /><br />
	</xsl:if>
</xsl:template>

<xsl:template match="post">
	* [<xsl:value-of select="@href" />](<xsl:value-of select="@href" />)<br />
</xsl:template>
<xsl:template match="see">
	* [`<xsl:apply-templates />`](#<xsl:apply-templates />)<br />
</xsl:template>
<xsl:template match="author">
	*   <xsl:choose>
			<xsl:when test="@href">
				[<xsl:apply-templates />](<xsl:value-of select="@href" />)
			</xsl:when>
			<xsl:otherwise>
				<xsl:apply-templates />
			</xsl:otherwise>
		</xsl:choose>
	<br />
</xsl:template>
<xsl:template match="problem">
	<br /><xsl:apply-templates /><br />
</xsl:template>
<xsl:template match="solution">
	<br /><xsl:apply-templates /><br />
</xsl:template>

<xsl:template match="fixeslist"><xsl:apply-templates /></xsl:template>

<xsl:template match="fixes">
	* [<xsl:apply-templates />](#FIX_<xsl:apply-templates />)<br />
</xsl:template>

</xsl:stylesheet>

